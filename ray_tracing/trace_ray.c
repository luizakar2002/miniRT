#include "minirt.h"

void	ray_tracing(void *mlx, void *win, t_scene *scene)
{
	int			mlx_x;
	int			mlx_y; //for mlx_pixel_put
	float		x_angle;
	float		y_angle;
	int			color;
	float		x_ray;
	float		y_ray;
	t_vector	*ray;
	t_plane		*vplane;

	printf("0");
	vplane = get_view_plane(scene->width, scene->height, scene->cams->fov);
	mlx_y = 0;
	y_angle = (scene->height / 2);
	while (y_angle >= (scene->height / 2) * (-1))
	{
		y_ray = y_angle * vplane->y_pixel;
		x_angle = (scene->width / 2) * (-1);
		mlx_x = 0;
		while (x_angle <= (scene->width / 2))
		{
			printf("1\n");
			x_ray = x_angle * vplane->x_pixel;
			ray = new_vector(x_ray, y_ray, -1);
			vec_normalize(ray);
			if(sphere_intersect(scene->cams, ray, scene->sphere))
				color = 16777215;
			else
				color = 0;
			mlx_pixel_put(mlx, win, mlx_x, mlx_y, color);
			free(ray);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
	printf("2\n");
}

t_plane		*get_view_plane(float width, float height, float fov)
{
	t_plane	*vplane;
	float	ratio;
	
	fov = 1; //just for now, then should be changed
	vplane = malloc(sizeof(t_plane));
	if(!vplane)
		error_exit(-1);
	ratio = width / height;
	vplane->width = 1;
	vplane->height = vplane->width / ratio;
	vplane->x_pixel = vplane->width / width;
	vplane->y_pixel = vplane->height / height;
	return (vplane);
}
