mkdir -p obj
gcc -Wall -Wextra -pedantic -std=c11 -fno-common -fno-builtin -D_POSIX_C_SOURCE=200809L -Ilib -g -c main.c -o obj/main.o
gcc -Wall -Wextra -pedantic -std=c11 -fno-common -fno-builtin -D_POSIX_C_SOURCE=200809L -Ilib -g -c lib/affichage.c -o obj/affichage.o
gcc -Wall -Wextra -pedantic -std=c11 -fno-common -fno-builtin -D_POSIX_C_SOURCE=200809L -Ilib -g -c lib/caissiere.c -o obj/caissiere.o
gcc -Wall -Wextra -pedantic -std=c11 -fno-common -fno-builtin -D_POSIX_C_SOURCE=200809L -Ilib -g -c lib/client.c -o obj/client.o
gcc -Wall -Wextra -pedantic -std=c11 -fno-common -fno-builtin -D_POSIX_C_SOURCE=200809L -Ilib -g -c lib/jour.c -o obj/jour.o
gcc -Wall -Wextra -pedantic -std=c11 -fno-common -fno-builtin -D_POSIX_C_SOURCE=200809L -Ilib -g -c lib/ticket.c -o obj/ticket.o
gcc -Wall -Wextra -pedantic -std=c11 -fno-common -fno-builtin -D_POSIX_C_SOURCE=200809L -Ilib -g -c lib/utils.c -o obj/utils.o
mkdir -p bin
gcc -Wall -Wextra -pedantic -std=c11 -fno-common -fno-builtin -D_POSIX_C_SOURCE=200809L -Ilib -g obj/main.o obj/affichage.o obj/caissiere.o obj/client.o obj/jour.o obj/ticket.o obj/utils.o -o bin/s101