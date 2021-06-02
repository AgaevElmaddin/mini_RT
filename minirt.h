#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# include "./minilibx_mms/mlx.h"
# include "./vector_operations/vector_operations.h"
# include "./different_errors/different_errors.h"
# include "./scenes/camera.h"
# include "./scenes/scene.h"
# include "./scenes/colour.h"
# include "./calculations/ray.h"
# include "./scenes/colour.h"
# include "./subfunctions/subfunctions.h"
# include "./subfunctions/get_next_line.h"
# include "./investigation_of_data/investigation_of_data.h"
# include "./get_objects/get_objects.h"
# include "./calculations/coeff.h"
# include "./objects_normal/objects_normal.h"

# define HEADER 54

char	*bmp_header(t_scene scene, unsigned int *size);
void	save_bmp_file(t_scene scene);

#endif
