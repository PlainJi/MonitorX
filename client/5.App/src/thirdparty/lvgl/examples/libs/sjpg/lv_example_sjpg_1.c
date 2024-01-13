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
    //lv_img_set_src(test_img, "A:image/face.png");
    extern const char *ui_img_face_png;
    lv_img_set_src(test_img, ui_img_face_png);
    lv_obj_set_width(test_img, 48);
    lv_obj_set_height(test_img, 48);
    lv_obj_set_x(test_img, 240);
    lv_obj_set_y(test_img, -72);
    lv_obj_set_align(test_img, LV_ALIGN_CENTER);
    lv_obj_add_flag(test_img, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(test_img, LV_OBJ_FLAG_SCROLLABLE);
    //ui_creat_img(test_img, &ui_ImageFace, 240, -72, 48, 48, IMG(face));
    #endif
}

#endif
