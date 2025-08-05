/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:17:21 by aluther-          #+#    #+#             */
/*   Updated: 2025/06/30 18:17:23 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_join(int fd, char *stash)
{
	char	*buffer;		//declaramos el buffer
	ssize_t	bytes;			//declaramos la variable donde vamos a almacenar el retorno de read()
	char	*tmp;			//declaramos una string temporal que usaremos para mover/almacenar datos

	buffer = malloc(BUFFER_SIZE + 1);	//asignamos memoria dinamica del heap a buffer. Es importante hacerlo con malloc para poder tener memoria suficiente
	if (!buffer)						//comprobamos si se ha asignado la memoria correctamente
		return (NULL);					//devolvemos NULL en caso de que haya habido algun fallo
	bytes = 1;  										//para poder iniciar el siguiente bucle al menos una vez hemos de asignar a bytes el valor de 1
	while (!ft_strchr(stash, '\n') && bytes > 0)		//creamos el bucle. Entraremos mientras no se encuentre un \n y el valor de bytes sea > 0
	{
		bytes = read(fd, buffer, BUFFER_SIZE);			//leemos el archivo y almacenamos en la variable el valor que retorna read
		if (bytes < 0)									//comprobamos primero el valor retornado para evitar fallos (si read retorna -1 u otro valor < 0)
			return (free(buffer), free(stash), NULL);	//Caso de fallo, liberamos tanto el stash como el buffer y devolvemos NULL. Importante  hacerlo para evitar segmentatio fault
		buffer[bytes] = '\0';		//Si no ha fallado la lectura, aseguraremos el caracter nulo en la ultima posicion del buffer
		tmp = ft_strjoin(stash, buffer);	//almacenaremos de forma temporal la union de stash y buffer, para poder ir construyendo correctamente en caso de que aun no hayamos acabado de leer la linea
		free(stash);	//liberamos el stash
		stash = tmp;	//almacenamos el nuevo valor en stash. En la primera llamada el valor de stash estara vacio asi que solo sera el del buffer. Pero en caso de que el buffer sea pequeno y haya que hacer varias llamadas para leer una linea completa, este metodo ira construyendo la linea hasta que encontremos un salto de linea.
	}
	free(buffer); //Cuando ya hayamos encontrado un salto de linea o no se haya leido nada del documento, liberamos el buffer
	return (stash); //devolvemos el valor de stash, que sera la linea
}

static char	*extract_line(char *stash)
{
	int	i;		//declaracion de indice

	if (!stash || stash[0] == '\0')	//comprovamos el valor y nos aseguramos de que haya datos validos o de que no sea una string vacia. Es una doble comprobacion, quizas redundante.
		return (NULL);			//devolvemos NULL en caso previo
	i = 0;										//asignamos la posicion inicial del indice
	while (stash[i] && stash[i] != '\n')		//mientras existan datos, y estos datos no sea un salto de linea...
		i++;									//iremos aumentando el indice. Esto es para imprimir toda la linea. Porque muy posiblemente tendremos datos almacenados entre llamadas de diferentes lineas.
	if (stash[i] == '\n')						//hemos encontrado un salto de linea!
		i++;									//hemos de incluirlo, asi que aumentamos el indice
	return (ft_substr(stash, 0, i));			//ahora extraemos la string de toda la linea que hayamos encontrado incluyendo el salto y devolvemos el valor
}

static char	*update_stash(char *stash)
{
	int		i;					//un indice
	char	*new_stash;			//el stash actualizado, que luego sera asignado al stash original asi que esta string solo se entiende dentro de esta funcion

	i = 0;						//comenzamos en la primera posicion
	while (stash[i] && stash[i] != '\n')	//mientras haya datos validos y no sea un salto de linea...
		i++;								//avanzamos!
	if (!stash[i])							//comprobamos si en la posicion que estamos tiene datos. Quizas no lo tiene y es \0, por lo que hemos de liberar en este caso ya que no hay mas datos que leer!
	{
		free(stash);						//liberamos el stash en caso de que no haya datos
		return (NULL);						//devolvemos NULL
	}
	i++;									//si hemos encontrado un \n, entonces hemos de saltarlo
	if (!stash[i])							//si despues del \n no hay datos validos, liberamos y devolvemos NULL
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strdup(stash + i);		//sI despues de \n si hay datos, entonces hacemos una duplicacion DESDE i hasta el final de la string
	free(stash);							//liberamos el stash original (ya que luego le asingaremos solo los datos que nos se han imprimido aun)
	return (new_stash);						//devolvemos el stash actualizado para asignarlo!
}

static char	*free_and_null(char **ptr)
{
	if (*ptr)			//se comprueba si tiene memoria asignada
		free(*ptr);		//se libera la memoria
	*ptr = NULL;		//aseguramos la asignacion a nulo
	return (NULL);		//devolvemos NULL, que se devolvera a la get_next_line general
}

char	*get_next_line(int fd)
{
	static char	*stash;		//string donde guardaremos los datos del buffer, static para manetener el valor guardado entre llamadas
	char		*line; 		//string final a imprimir

	if (fd < 0 || BUFFER_SIZE <= 0)	//comprobamos si el buffer size y el fd son validos
		return (NULL);				//devolvemos null en caso de que no lo sean
	stash = read_and_join(fd, stash);	//empezamos a rellenar el stash ---> vamos a read_and_join
	if (!stash || stash[0] == '\0') 	//ahora que tenemos el stash lleno, hemos de comprobar si estamos un stash valido o en el final del documento
		return (free_and_null(&stash)); //si el valor de stash es erroneo o no tiene datos, nos aseguramos de liberar memoria y asignar el null con ---> free_and_null    El segundo caso puede pasar con archivos vacios o con el final del archivo
	line = extract_line(stash); //OH! el stash si tenia datos validos. Vamos entonces extraer la linea completa (ya que puede que haya mas datos!) ---> extract_line
	stash = update_stash(stash);	//ahora he hemos extraido la linea, hemos de dejar en el stash solo los datos que no hayamos usado para la siguiente llamada. Asi que hemos de actualizar el stash con ---> update_stash
	return (line);					//toma ya, ahora que hemos hecho todo y tenemos una linea y el stash actualizado para la siguiente llamada, entonces devolvemos la linea leida y que el main haga lo que le de la gana con ella :)
}
