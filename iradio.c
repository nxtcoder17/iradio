#include <stdio.h>
#include <string.h>
#include <gst/gst.h>

int main(int argc, char* argv[])
{
    GstElement * pipeline = NULL;
    GstBus *bus = NULL;
    GstMessage *msg = NULL;

    printf("============ Started GStreamer ===========\n");

    gst_init (&argc, &argv);

    printf(" [+] Command Line Arguments: \n");
    for (int i=1; i < argc; ++i) {
        printf("\t [%d]: %s\n", i, argv[i]);
    }

    char playbin_uri[1000] = "playbin uri=";
    printf("\n\n");
    printf("[+] [BUILDING playbin]: %s\n", playbin_uri);

    printf("[-] [CL_STATUS]: %d\n", strcmp(argv[1], "-f"));
    if ( strcmp(argv[1], "-f") == 0) {
        strcat(playbin_uri, "file://");
        strcat(playbin_uri, argv[2]);
    } else {
        strcat(playbin_uri, argv[1]);
    }


    printf("[+1] [BUILDING playbin]: %s\n", playbin_uri);

    /* Building the pipeline */
    pipeline = gst_parse_launch(playbin_uri, NULL);
    printf("[+2] [BUILDING playbin]: %s\n", playbin_uri);

    /* Starting the PlayBack */
    gst_element_set_state(pipeline, GST_STATE_PLAYING);

    /* Wait Until Error or EOS Occurs */
    bus = gst_element_get_bus(pipeline);
    msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE,
                            GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

    /* Freeing Up the resources */
    if (msg != NULL)
        gst_object_unref (msg);
    gst_object_unref (bus);
    gst_element_set_state (pipeline, GST_STATE_NULL);
    gst_object_unref (pipeline);
    return 0;
}
