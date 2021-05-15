#ifndef SCENE_H
# define SCENE_H
#include "camera.h"
#include "sphere.h"

typedef struct s_scene
{
	t_camera	*cams;
	t_sphere	*sphere;
	float		width;
	float		height;
}				t_scene;

t_scene		*new_scene(t_camera *cam, t_sphere *sphere);

#endif
