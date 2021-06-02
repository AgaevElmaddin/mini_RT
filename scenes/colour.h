#ifndef COLOUR_H
# define COLOUR_H

typedef struct s_colour
{
	int	red;
	int	green;
	int	blue;
}				t_colour;

typedef union u_colour_decimal
{
	int				to_decimal;
	unsigned char	mas_for_rgb[4];
}			t_colour_decimal;

t_colour	translate_decimal_to_rgb(int colour);
int			translate_rgb_to_decimal(t_colour colour);

#endif
