A método mais fácil e garantido de compilar e executar o programa é utilizando Docker
```
docker buildx build . -t moneypot_run --target run && docker container run --name moneypot_run --rm -it moneypot_run
```

