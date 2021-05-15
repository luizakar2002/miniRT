#ifndef VIEW_PLANE_H
# define VIEW_PLANE_H
#include "scene.h"

typedef	struct	s_plane
{
	float	width;
	float	height;
	float	x_pixel; // pixel of camera plane
	float	y_pixel;
}				t_plane;

t_plane		*get_view_plane(float width, float height, float fov);
int			sphere_intersect(t_camera *cam, t_vector *ray, t_sphere *sphere);
void		ray_tracing(void *mlx, void *win, t_scene *scene);

#endif
