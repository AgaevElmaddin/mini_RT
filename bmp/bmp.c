#include "../minirt.h"

typedef struct s_bmp
{
	int				fd;
	unsigned int	size;
	int				i;
	char			*data;
}				t_bmp;

char	*bmp_header(t_scene scene, unsigned int *size)
{
	t_bmp	bmp;

	bmp.i = 0;
	*size = scene.viewport->height * scene.viewport->width * 3;
	bmp.data = malloc(*size + HEADER);
	if (!bmp.data)
		return (NULL);
	while (bmp.i < (int)*size + HEADER)
		bmp.data[bmp.i++] = 0;
	*(unsigned short *)bmp.data = *(const unsigned int *)(unsigned long)"BM";
	*(unsigned int *)(bmp.data + 2) = (*size + HEADER);
	*(unsigned int *)(bmp.data + 6) = 0u;
	*(unsigned char *)(bmp.data + 10) = HEADER;
	*(unsigned int *)(bmp.data + 14) = 40;
	*(unsigned int *)(bmp.data + 18) = scene.viewport->width;
	*(unsigned int *)(bmp.data + 22) = scene.viewport->height;
	*(unsigned short *)(bmp.data + 26) = 1;
	*(unsigned short *)(bmp.data + 28) = 24;
	*(unsigned int *)(bmp.data + 30) = 0;
	*(unsigned int *)(bmp.data + 34) = (unsigned int)*size;
	*(unsigned int *)(bmp.data + 38) = 3780;
	*(unsigned int *)(bmp.data + 42) = 3780;
	*(int *)(bmp.data + 46) = 0;
	*(int *)(bmp.data + 50) = 0;
	return (bmp.data);
}

void	save_bmp_file(t_scene scene)
{
	t_bmp			bmp;
	char			*data;
	int				mas[4];

	scene.viewport->width -= scene.viewport->width % 16;
	data = bmp_header(scene, &bmp.size);
	mas[0] = HEADER;
	mas[3] = scene.viewport->height;
	while (mas[3]--)
	{
		mas[2] = -1;
		while (++mas[2] < scene.viewport->width)
		{
			mas[1] = mas[2] * (scene.mlx.bpp / 8)
				+ mas[3] * scene.mlx.len_line;
			*(data +mas[0]++) = *(scene.mlx.data + mas[1]++);
			*(data +mas[0]++) = *(scene.mlx.data + mas[1]++);
			*(data +mas[0]++) = *(scene.mlx.data + mas[1]);
		}
	}
	bmp.fd = open("triangle.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (bmp.fd < 0)
		return ;
	write(bmp.fd, data, bmp.size + HEADER);
	close(bmp.fd);
}
