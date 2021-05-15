#include "/Users/lukarape/Desktop/miniRT/includes/minirt.h"

int	main(void)
{
	void *mlx;
	void *win;
	
	printf("a\n");
	mlx = mlx_init();
	printf("0\n");
	t_vector	*sphere_center = new_vector(3, 2, -40);
	printf("1\n");
	t_sphere	*sphere = new_sphere(sphere_center, 6);
	printf("2\n");
	t_vector	*cam_origin = new_vector(0, 0, 0);
	printf("3\n");
	t_vector	*cam_dir = new_vector(0, 0, 0);
	printf("4\n");
	t_camera	*cam = new_camera(cam_origin, cam_dir, 70);
	printf("5\n");
	t_scene		*scene = new_scene(cam, sphere);
	printf("6\n");
	scene->width = 800;
	scene->height = 600;
	win = mlx_new_window(mlx, scene->width, scene->height, "test");
	ray_tracing(mlx, win, scene);
	free_scene(scene);
	mlx_loop(mlx);
	return (0);
}
