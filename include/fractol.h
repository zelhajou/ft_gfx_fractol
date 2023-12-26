/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 01:05:50 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/26 23:19:29 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include <mlx.h>

// Window
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800
// keys
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
// Mouse
# define MOUSE_LEFT_CLICK 1
# define MOUSE_RIGHT_CLICK 2
# define MOUSE_MIDDLE_CLICK 3
# define ZOOM_IN_KEY 4
# define ZOOM_OUT_KEY 5

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_fractol
{
	// Window and image info
	void		*mlx_connextion;
	void		*mlx_window;
	t_image		image;
	// complex numbers
	t_complex	c;
	t_complex	z;
	// Fractal specific parameters
	double		zoom;
	t_point		offset;
	int			max_iterations;
}	t_fractol;

// Graphics_env
void	ft_setup_window(t_fractol *fractol);
int		ft_close_window(t_fractol *fractol);
// Draw
int		ft_render_fractal(t_fractol *fractol);
void	put_pixel_to_image(t_fractol *fractol, int x, int y, int color);
// Events
int		ft_handle_keypress(int key, t_fractol *fractol);
int		ft_handle_mouse(int button, int x, int y, t_fractol *fractol);
void	ft_setup_hooks(t_fractol *fractol);

// fractal sets
int iterate_fractal(t_complex z, t_complex c, int max_iterations);
int calculate_mandelbrot(t_fractol *fractol, int max_iterations);
int calculate_julia(t_fractol *fractol, int max_iterations);

// int calculate_mandelbrot(t_fractol *fractol, int max_iterations);
// int calculate_julia(t_fractol *fractol, int max_iterations);

#endif
