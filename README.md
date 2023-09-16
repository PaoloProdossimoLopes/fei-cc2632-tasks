# Projeto 1 - Lista de tarefas
Para este primeiro projeto você deverá implementar um programa que gerencia uma lista de tarefas, sendo que cada tarefa deve conter uma descrição, uma categoria e uma prioridade (quanto maior o valor, maior a prioridade da tarefa). Seu programa deve conseguir armazenar até 100 tarefas e permitir que o usuário cadastre, delete e liste as tarefas.

Nesta parte do projeto, ainda não teremos nenhum tipo de filtro ou ordenação das tarefas e seu objetivo é apenas mater os dados armazenados de forma que o usuário consiga usar as informações.

A interação do usuário com o seu programa deve ser definida por você, porém as 3 operações (cadastrar, lista e deletar) são obrigatórias.

## Requisitos
- O projeto deve ser desenvolvido em C;
- O programa deve ser capaz de armazenar até 100 tarefas;
- O usuário deve poder criar, deletar, listar todas as tarefas;
- Os dados das tarefas devem ser armazenados em arquivos binários usando funções para armazenar os dados em arquivos binários (fread e fwrite);

### Formato dos dados
Um array de struct contendo:

- Prioridade da tarefa (valor inteiro entre 0 e 10);
- Descrição da tarefa (array de char de até 300 letras);
- Categoria (array de char de até 100 letras);

### Limitações
1. Não será permitido o uso de bibliotecas além do que já é oferecido no momento da instalação. O projeto receberá nota zero se utilizar bibliotecas não desenvolvidas por você;
2. Caso seja detectado código copiado ou qualquer forma de plágio, a nota será zerada.
3. O código deve ser comentado de forma a explicar a lógica desenvolvida ao longo do código e isto pode afetar a nota;
4. O projeto pode ser desenvolvido em qualquer sistema operacional e com qualquer IDE ou editor de texto. Porém, para a avaliação, a compilação e execução serão realizadas no replit e será avaliado o funcionamento do programa no ambiente fornecido pelo serviço;
5. Serão aceitos projetos armazenados em serviços de versionamento de código como Github, Gitlab, Bitbucket, etc. Porém o histórico de `commit`s poderá ser utilizado na avaliação do projeto. Não serão aceitos endereços do replit como entrega de código.

### Critérios de avaliação
#### Código organizado e bem escrito: 
- dividido em funções;
- código formatado;
- bons nomes de variáveis e funções;
- uso correto dos tipos de variáveis;

#### Funcionamento:
- programa funciona corretamente;
- erros são tratados;
- usabilidade (se é possível entender como interagir com o programa);
- todas as funções pedidas estão presentes;

#### Documentação:
- o código está comentado;
- é possível entender a lógica a partir dos comentários no código;

### Entrega
É necessário entregar:
- Código fonte do projeto desenvolvido. Caso o código esteja em um sistema de versionamento de código (Github, Gitlab, etc), o endereço do repositório deve estar no PDF
- 
Não é necessário entregar:
- Binário compilado;
- Documentação sobre como usar o programa.
