// Max number of candidates
const MAX = 9;

//Array for candidates
let canditatos = [];

// Candidates have name and vote count
class Candidato {
  constructor(name, votes) {
    this.name = name;
    this.votes = votes;
  }
}

//Função para criar canditatos
const candidatoCreator = (nome_candidatos) => {
  if (nome_candidatos.length > MAX) {
    console.log("Número de candidatos invalidado para realizar a eleição");
    return;
  } else {
    nome_candidatos.forEach((nome) => {
      //Criando candidato e adicionando no array

      canditatos.push(new Candidato(nome, 0));

      return console.log(`Candidato ${nome} criado com sucesso!!`);
    });
  }
};

//Função para votar

const votar = (voto_eleitor) => {
  for (let index = 0; index < voto_eleitor.length; index++) {
    let participante = canditatos.find((c) => c.name === voto_eleitor[index]); //find é uma função callback que espera uma função, e retorna um objeto se encontrar, senão undefined
    if (participante) {
      //If verifica se o valor é nulo ou não-nulo, então para simplificar podemos passar apenas o objeto retornado por find.
      console.log(`Voto válidado para o candidato ${voto_eleitor[index]}`);
      participante.votes++;
    } else {
      console.log(
        `Voto inválido! Candidato ${voto_eleitor[index]} não encontrado.`
      );
    }
  }
};

//Função para contabilizar votos
const declararVencedor = () => {
  let maior = 0;
  let vencedores = [];

  canditatos.forEach((candidato) => {
    if (candidato.votes > maior) {
      maior = candidato.votes;
      // Adiciona o primeiro nome a lista de vencedores
      vencedores = [candidato.name];
    }
    // Adiciona mais um nome em caso de empate
    else if (candidato.votes === maior) {
      vencedores.push(candidato.name);
    }
  });

  console.log("Vencedor(es):", vencedores.join(", "));
};

candidatoCreator(["Caio", "Ribamar", "Pedro"]); //Para usar a função forEach, obrigatoriamente o que tem que ser iterado é um Array
votar([
  "Ribamar",
  "Caio",
  "Ribamar",
  "Pedro",
  "José",
  "CaioU",
  "Ribamar",
  "Pedin",
  "Pedro",
]);
declararVencedor(canditatos);

//Outra abordagem da função votar
// const votar = (voto_eleitor) => {
//Essa variavel serve como um break do nosso forEach, tendo em vista que as instruções são executadas para todos do array, essa flag quebra o loop se encontramos o que procuramos.
//   let candidatoEncontrado = false;

//   candidatos.forEach((participante) => {
//     if (voto_eleitor === participante.name) {
//       participante.votes++;
//       candidatoEncontrado = true;
//       console.log(`Voto válidado para o candidato ${participante.name}`);
//     }
//   });

//   if (!candidatoEncontrado) {
//     console.log("Voto inválido! Candidato não encontrado.");
//   }
// };
