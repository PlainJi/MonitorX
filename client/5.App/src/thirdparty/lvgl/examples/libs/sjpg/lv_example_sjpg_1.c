#include "../../lv_examples.h"
#if LV_USE_SJPG && LV_BUILD_EXAMPLES

/**
 * Load an SJPG image
 */
void lv_example_sjpg_1(void)
{
    #if 0
    lv_obj_t * wp;

    wp = lv_img_create(lv_scr_act());
    /* Assuming a File system is attached to letter 'A'
     * E.g. set LV_USE_FS_STDIO 'A' in lv_conf.h */
    lv_img_set_src(wp, "A:lvgl/examples/libs/sjpg/small_image.sjpg");
    #else 
    lv_obj_t * test_img;
    test_img = lv_img_create(lv_scr_act());
    lv_img_set_src(test_img, "A:image/bg.png");
    #endif
}

#endif
