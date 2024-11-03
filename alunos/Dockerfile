FROM gcc:14.2 AS build
WORKDIR /src
COPY main.c .
RUN gcc -static `#-O1` main.c -o alunos.exe

FROM scratch AS run
WORKDIR /run
COPY --from=build /src/alunos.exe .
CMD ["/run/alunos.exe"]

