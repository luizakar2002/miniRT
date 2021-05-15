#include "minirt.h"

void	free_scene(t_scene *scene)
{
	free(scene->cams->origin);
	free(scene->cams->direction);
	free(scene->cams);
	free(scene->sphere->center);
	free(scene->sphere);
	free(scene);
}
