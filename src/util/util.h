/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:03:45 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/10 16:14:13 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

unsigned int	arr_len(void *arr);
void			arr_free(void *data);

void			free_and_null(void *data);
void			free_non_null(void *data);

#endif