#include <mlx.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;
int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

unsigned char	get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}
int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_line(t_data* data, int x, int y, int len, int color) 
{
	int j = 0;
	while (j < len) {
		my_mlx_pixel_put(data, x + j, y, color);
		j++;
	}
}


void draw_cube(t_data* data, int x, int y, int size, int color) 
{
	int k = 0;
	int rayon = 250;
	int i = x + 250;
	int j = y - 350;
	while (k < size) {
		
		my_mlx_pixel_put(data, x + k, y, color);
		my_mlx_pixel_put(data, x, y + k, color);
		my_mlx_pixel_put(data, x + k, y + size , color);
		my_mlx_pixel_put(data, x + size  , y + k, color);
		my_mlx_pixel_put(data,i + rayon * cos(k * PI * 2/ 360),j + rayon * sin(k * PI * 2 / 360),color);
		k++;
	}
	
}
int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	img;
	t_vars	vars;
	int width;
	int height;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 1920, 1200, "so_longg");
	img.img = mlx_new_image(mlx_ptr, 1920, 1200);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	//vars.mlx = mlx_init();
	//vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	//mlx_key_hook(vars.win, key_hook, &vars);
	//mlx_mouse_hook(vars.win, mouse_hook, &vars);
	//void* imgg = mlx_xpm_file_to_image(mlx_ptr, "NightBorne_idle/player3.xpm", &width, &height);
	mlx_put_image_to_window(mlx_ptr, mlx_win,img.img, 25, 25);
	//my_mlx_pixel_put(&img, 700, 700, 0x00FF0000);
	//draw_line(&img,500,500,500,0xB0E0E6);
	draw_cube(&img, 500, 600, 500, 0xB0E0E6);
	mlx_put_image_to_window(mlx_ptr, mlx_win,img.img, 50, 50);
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, mlx_win);
	free(mlx_ptr);
	}