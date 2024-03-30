/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:02:11 by yumamur           #+#    #+#             */
/*   Updated: 2024/03/29 01:10:17 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"
#include "objects/t_core.h"
#include "objects/t_light.h"
#include "objects/t_obj.h"
#include "libft/libft.h"
#include <stdio.h>

void render(t_scene *scene)
{
	printf("Rendering scene\n");
	printf("Camera:\n");
	printf("  position: %f %f %f\n", scene->camera.position.x, scene->camera.position.y, scene->camera.position.z);
	printf("  orientation: %f %f %f\n", scene->camera.orientation.x, scene->camera.orientation.y, scene->camera.orientation.z);
	printf("  rotation: %f %f %f\n", scene->camera.rotation.x, scene->camera.rotation.y, scene->camera.rotation.z);
	printf("  fov: %f\n", scene->camera.fov);

	int i = 0;
	printf("\nLights:\n");
	for (t_list *light = scene->lights; light; light = light->next)
	{
		t_light *l = light->content;
		printf(" index: %d\n", i++);
		printf("  type: %d\n", l->type);
		printf("  position: %f %f %f\n", l->position.x, l->position.y, l->position.z);
		printf("  color: %f %f %f\n", l->color.x, l->color.y, l->color.z);
		printf("  intensity: %f\n", l->intensity);
	}

	i = 0;
	printf("\nObjects:\n");
	for (t_list *obj = scene->objects; obj; obj = obj->next)
	{
		t_obj_base *o = obj->content;
		printf(" index: %d\n", i++);
		printf("  type: %d\n", o->type);
		printf("  position: %f %f %f\n", o->position.x, o->position.y, o->position.z);
		printf("  rotation: %f %f %f\n", o->rotation.x, o->rotation.y, o->rotation.z);
		printf("  color: %f %f %f\n", o->color.x, o->color.y, o->color.z);
		printf("  reflectivity: %f\n", o->reflectivity);
	}
	// ft_lstclear(scene, free);
}

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (!is_valid(argc, argv))
		return (1);
	scene = parse(argv[1]);
	if (!scene.camera.fov || !scene.objects || !scene.lights)
		// TODO: free scene
		return (0);
	render(&scene);
	return (0);
}
