#ifndef SCENE_H
# define SCENE_H

typedef struct s_canvas
{
	int		width;
	int		height;
	int		d;
}				t_canvas;

typedef struct s_colour_op
{
	int	red;
	int	green;
	int	blue;
}				t_colour_op;

typedef struct s_sphere
{
	t_vector	center;
	double		diameter;
	t_colour_op	rgb;
}				t_sphere;

typedef struct s_d_and_h
{
	double	diameter;
	double	height;
}				t_d_and_h;

typedef struct s_cylinder
{
	t_vector	a;
	t_vector	orientation;
	double		diameter;
	double		height;
	t_colour_op	rgb;
}				t_cylinder;

typedef struct s_plane
{
	t_vector	p0;
	t_vector	orientation;
	t_colour_op	rgb;
}				t_plane;

typedef struct s_square
{
	t_vector	center;
	t_vector	orientation;
	double		side;
	t_colour_op	rgb;
}				t_square;

typedef struct s_triangle
{
	t_vector	first_point;
	t_vector	second_point;
	t_vector	third_point;
	t_colour_op	rgb;
}				t_triangle;

typedef struct s_light
{
	t_vector	light_point;
	double		brightness;
	t_colour_op	rgb;
}				t_light;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_lobject
{
	int		type;
	void	*obj;
	void	*next;
}				t_lobject;

typedef enum e_object_name
{
	SPHERE,
	PLANE,
	SQUARE,
	CYLINDER,
	TRIANGLE,
	LIGHT,
	CAMERA,
}				t_object_name;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*data;
	int		bpp;
	int		len_line;
	int		endian;
}				t_mlx;

typedef struct s_light_shadow
{
	t_vector	norm_shape;
	t_colour_op	rgb;
	t_colour_op	tmp_rgb;
	t_lobject	*list;
	double		light_v;
	double		d_light_i;
	t_vector	light_ray;
}				t_light_shadow;

typedef struct s_scene
{
	t_lobject	*cameras;
	t_lobject	*objs;
	t_lobject	*lights;
	t_colour_op	background_colour;
	t_light		*ambient;
	t_mlx		mlx;
	t_canvas	*viewport;
}				t_scene;

void			mlx_initialization(t_scene *scene);
void			scene_initialization(t_scene *scene);
void			intersection_initialization(double (*hit_obj[5])(t_vector ray,
						t_vector origin, void *object));
void			g_normal_initialization(t_vector (*get_norm[5])(t_vector p,
						t_lobject *shape, t_colour_op *rgb,
						t_vector ray_origin));

int				exit_program(void);
int				key_proc(int key, t_scene *scene);

void			put_new_pixel(t_mlx *mlx, int j, int i, t_colour_op rgb);
t_vector		camera_matrix(t_scene *scene, int i, int j);
t_vector		intersection(t_vector ray, t_scene *scene,
					t_lobject **current_obj);
void			rendering(t_scene *scene);

double			get_shadow(t_vector ray, t_vector p, t_scene *scene);
void			get_shadow2(t_vector ray, t_scene *scene,
					 t_light_shadow *shadow);
t_colour_op		get_shadow1(t_vector ray, t_scene *scene,
					t_lobject *current_shape);

t_canvas		*create_canvas(int width, int height, int d);

t_colour_op		create_colour(int red, int green, int blue);
t_colour_op		colour_addition(t_colour_op rgb1, t_colour_op rgb2);
int				colour_op_validation(t_colour_op rgb);
t_colour_op		ambient_light(t_colour_op rgb, t_light *light);
t_colour_op		diffuse_light(t_colour_op rgb, t_light *light,
					double dot_angle);
void			get_colour(t_colour_op *rgb, char *str, char *message);
int				create_trgb(t_colour_op rgb);

t_light			*create_light(t_vector light_point, double brightness,
					t_colour_op rgb);
t_sphere		*create_sphere(t_vector center, double radius, t_colour_op rgb);
t_cylinder		*create_cylinder(t_vector a, t_vector orientation,
					t_d_and_h d_and_h, t_colour_op rgb);
t_plane			*create_plane(t_vector p0, t_vector orientation,
					t_colour_op rgb);
t_square		*create_square(t_vector center, t_vector orientation,
					double side, t_colour_op rgb);
t_triangle		*create_triangle(t_vector first_point, t_vector second_point,
					t_vector third_point, t_colour_op rgb);

#endif
