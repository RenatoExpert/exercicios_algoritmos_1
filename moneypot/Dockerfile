FROM gcc:14.2 AS build
WORKDIR /src
COPY main.c .
RUN gcc -static `#-O1` main.c -o moneypot.exe

FROM scratch AS run
WORKDIR /run
COPY --from=build /src/moneypot.exe .
CMD ["/run/moneypot.exe"]

