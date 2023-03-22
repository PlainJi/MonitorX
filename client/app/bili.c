#include "bili.h"
#include "curldef.h"
#include "curl/curl.h"
#include "curl/easy.h"

#define URL_BILI_RELATION   "https://api.bilibili.com/x/relation/stat?vmid=389426697"
#define URL_BILI_VIDEO_LIST "https://api.bilibili.com/x/space/arc/search?mid=389426697&pn=1&ps=25"
#define URL_BILI_VIDEO_INFO "https://api.bilibili.com/x/web-interface/archive/stat?aid=590023490"
//#define URL_BILI_SPACE      "https://api.bilibili.com/x/space/upstat?mid=389426697"       // need cookie

void bili_thread(void) {
    CURLcode res;
	CURL *curl = NULL;
	char *utfStr = NULL;
	char *body = NULL;
	struct MemoryStruct chunk;
	memset(&chunk, 0, sizeof(chunk));

    printf("%s\n", curl_version());

    do {
        curl_global_init(CURL_GLOBAL_ALL);
       	curl = curl_easy_init();
        //curl_easy_setopt(curl, CURLOPT_VERBOSE, true);
        curl_easy_setopt(curl, CURLOPT_URL, URL_BILI_RELATION);
        //curl_easy_setopt(curl, CURLOPT_URL, URL_BILI_SPACE);
        //curl_easy_setopt(curl, CURLOPT_URL, URL_BILI_VIDEO_INFO);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            printf("perform curl error:%d.\n", res);
            break;
        }
        printf("%lu %s\n", (long unsigned int)chunk.size, chunk.memory);
        //update_git((const char*)chunk.memory);
        sleep(1);
    }while(1);

    if(chunk.memory) free(chunk.memory);
	if(curl) curl_easy_cleanup(curl);
    curl_global_cleanup();
}