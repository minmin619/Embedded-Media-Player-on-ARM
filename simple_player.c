

#include <gst/gst.h>

int main(int argc, char *argv[]) {
    GstElement *pipeline;
    GMainLoop *loop;

    gst_init(&argc, &argv);
    
    if (argc != 2) {
        g_printerr("Usage: %s <video file>\n", argv[0]);
        return -1;
    }

    pipeline = gst_element_factory_make("playbin", "playbin");
    if (!pipeline) {
        g_printerr("Failed to create pipeline\n");
        return -1;
    }

    g_object_set(pipeline, "uri", g_strdup_printf("file://%s", argv[1]), NULL);

    loop = g_main_loop_new(NULL, FALSE);
    gst_element_set_state(pipeline, GST_STATE_PLAYING);
    
    g_print("Playing %s\n", argv[1]);
    g_main_loop_run(loop);

    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);
    return 0;
}

