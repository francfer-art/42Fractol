#include <pthread.h>

#define NUM_THREADS 12

 typedef struct {
    t_fractal *fractal;
    int start_row;
    int end_row;
} ThreadData;

 void *render_thread(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    t_fractal *fractal = data->fractal;
    int start_row = data->start_row;
    int end_row = data->end_row;

    for (int y = start_row; y < end_row; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            handle_pixel(x, y, fractal);
        }
    }

    pthread_exit(NULL);
}

 void fractal_render(t_fractal *fractal) {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    int rows_per_thread = HEIGHT / NUM_THREADS;
    int remainder = HEIGHT % NUM_THREADS;
    int start_row = 0;

    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_data[i].fractal = fractal;
        thread_data[i].start_row = start_row;
        thread_data[i].end_row = start_row + rows_per_thread
	+ (i < remainder ? 1 : 0);

        pthread_create(&threads[i], NULL, render_thread,
	(void *)&thread_data[i]);

        start_row = thread_data[i].end_row;
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    mlx_put_image_to_window(fractal->mlx_connection,
                            fractal->mlx_window,
                            fractal->img.image_ptr,
                            0, 0);
}
