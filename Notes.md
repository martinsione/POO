


## Metodos de I/O archivos
```cpp
ios::app -> Escribe siempre al final
ios::trunc -> Elimina todo y escribe un nuevo archivo
ios::binary -> Accede al archivo en modo binario
ios::in -> Se abre el archivo en modo lectura, tambien sirve para modificar un valor en binario sin borrar el archivo
ios::out -> Se abre el archivo en modo escritura (Por defecto)
ios::ate -> El "cursor" se ubica al final al abrir el archivo
ios::nocreate -> Genera un error si el fichero no existe
ios::noreplace -> Genera un error si el fichero existe
```

## Metodos de ifstream/ofstream
```cpp
// Los terminados en g son de ifstream y los en p son de ofstream
tellg()/tellp() -> Consulta la posicion
seekg()/seekp() -> cambia la posicion
```
