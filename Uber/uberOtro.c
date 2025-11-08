            if (strcmp(request,"viaje")==0){

                printf("\nSolicitud de viaje recibida.\n");
                bool viaje_encontrado = false;

                while (!viaje_encontrado && i<NUM_AUTOS)
                {
                    int i = 0;
                    if (ubers[i].disponible)
                    {
                        int costo = rand() % 100 + 50;
                        sprintf(viaje, "%s %d %d", ubers[i].placas, costo, i);
                        ubers[i].disponible=false;
                        send(socket_nuevo_fd, viaje, strlen(viaje)+1, 0);
                        viaje_encontrado = true;
                        ganancia += costo;
                        totalViajes++;
                    }
                    i++;
                }

                int size_recv = read(socket_nuevo_fd, request, ETHSIZE);

                if (!viaje_encontrado){
                    strcpy(viaje, "No hay conductores");
                    send(socket_nuevo_fd, viaje, strlen(viaje)+1, 0);
                }
            }

            if (strcmp(request,"viaje_terminado")==0){
                printf("\nNotificación de viaje terminado recibida.\n");
                read(socket_nuevo_fd, datos_cliente, ETHSIZE);
                char placa_Temp[7];
                int costo_Temp= 0;

                sscanf(datos_cliente, "%s %d", placa_Temp, &costo_Temp);
                liberarUber(placa_Temp);
            }