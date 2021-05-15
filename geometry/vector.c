#include "minirt.h"

t_vector	*new_vector(float x, float y, float z)
{
	t_vector *vector;

	vector = malloc(sizeof(t_vector));
	if (!vector)
		error_exit(-1);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}

t_vector	*vec_subtract(t_vector *v1, t_vector *v2)
{
	t_vector *vec;

	vec = new_vector(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
	return (vec);
}

float	vec_length(t_vector *v)
{
	float len;
	len = sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	return (len);
}

void	vec_normalize(t_vector *v)
{
	float len;

	len = vec_length(v);
	v->x /= len;
	v->y /= len;
	v->z /= len;
}

float	dot_product(t_vector *v1, t_vector *v2)
{
	float n;

	n = (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
	return (n);
}
