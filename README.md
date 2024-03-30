
# Get started

- Clonar el repositorio
- Se dispone de un Makefile con las reglas `all`, `server`, `client`, `bonus`, `server_bonus`, `client_bonus`, `clean`, `fclean` y `re`
- Ejecutando el comando `make` se compilar dos binarios, `server` y `client`, que deben ser ejecutados de la siguiente forma:

Primero ejecutar `server`, que devuelve su PID:
```bash
./server
Server PID: [SERVER_PID]
```

Seguidamente ejecutar `client` en otro terminal. Este enviará el mensaje pasado al `server` cuyo PID se indica, imprimiéndolo por salida estándar.
```bash
./client [SERVER_PID] "[MENSAJE]"
```

- Igualmente es posible compilar el bonus con el comando `make bonus`

## Contenido 

- El repositorio contiene **minitalk**, cuarto proyecto del Cursus de 42, correspondiente al segundo círculo (Rank 02). En este punto del Cursus 42 puede elegirse entre realizar **minitalk** (Señales en UNIX) y **pipex** (Pipes en UNIX). En mi caso me decanté por el primero, ya que me interesaba aprender sobre el envío de señales entre procesos y sus resultados.
- El proyecto sigue la [Norminette](https://github.com/42School/norminette), norma de estilo oficial del Campus.

##  minitalk 42 Project (Rank 02)
Score: 125/100

Como se menciona más arriba, el proyecto consta de dos pequeños programas:    
`server`: Actúa de servidor. Muestra su PID al ejecutarse y permanece a la escucha de los mensajes que le envía el cliente.    
`client`: Actúa de cliente. Recibe por argumento el PID del servidor y el mensaje que quiere ser enviado.     

#### (BONUS)
Los bonus `server_bonus` y `client_bonus` deben aplicar:   
- El servidor comunica al cliente que el mensaje ha sido recibido   
- Es posible enviar caracteres unicode (esta feature se encuentra soportada en todo mi proyecto)   


