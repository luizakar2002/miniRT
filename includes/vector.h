#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vector
{
	float x;
	float y;
	float z;
}				t_vector;

t_vector	*new_vector(float x, float y, float z);
t_vector	*vec_subtract(t_vector *v1, t_vector *v2);
float		vec_length(t_vector *v);
void		vec_normalize(t_vector *v);
float		dot_product(t_vector *v1, t_vector *v2);

#endif
