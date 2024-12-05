/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:43:30 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/04 16:43:38 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char **make_tab(const char *file_path)
{
    char    **map;
    char    *txt;
    int     fd;
    int     rows;
    int     i;

    // Compter le nombre de lignes dans le fichier
    rows = 0;
    fd = open(file_path, O_RDONLY);
    if (fd < 0)
    {
        return (perror("Error opening file"),NULL);
    }
    while ((txt = get_next_line(fd)))
    {
        rows++;
        free(txt); // Libérer la ligne lue
    }
    close(fd);

    // Allouer l'espace pour le tableau de chaînes
    map = malloc(sizeof(char *) * (rows + 1)); // +1 pour NULL
    if (!map)
        return (NULL);

    // Lire le fichier et remplir le tableau
    fd = open(file_path, O_RDONLY);
    if (fd < 0)
    {
        free(map);
        return (perror("Error opening file"),NULL);
    }

    i = 0;
    while ((txt = get_next_line(fd)))
    {
        map[i] = strdup(txt); // Copier la ligne dans le tableau
        free(txt);            // Libérer la mémoire de get_next_line
        if (!map[i])
        {
            while (--i >= 0) // Libérer les lignes précédentes en cas d'erreur
                free(map[i]);
            free(map);
            close(fd);
            return (NULL);
        }
        i++;
    }
    map[i] = NULL; // Terminer le tableau par NULL
    close(fd);
    return (map);
}

int main(void)
{
    char **map;
    int   i;
    int   j;

    // Charger la map
    map = make_tab("maps/map.ber");
    if (!map)
        return (1);

    // Afficher la map
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            printf("%c", map[i][j]);
            j++;
        }
        printf("\n"); // Passer à la ligne suivante
        i++;
    }

    // Libérer la mémoire allouée pour la map
    i = 0;
    while (map[i])
        free(map[i++]);
    free(map);

    return (0);
}

