// Max number of candidates
const MAX = 9;

//Array for candidates
let candidatos = [];

// Candidates have name and vote count
class Candidato {
  constructor(name, votes) {
    this.name = name;
    this.votes = votes;
  }
}

//Função para criar candidatos
const candidatoCreator = (nome_candidatos) => {
  if (nome_candidatos.length > MAX) {
    console.log("Número de candidatos invalidado para realizar a eleição");
    return;
  } else {
    nome_candidatos.forEach((nome) => {
      //Criando candidato e adicionando no array

      candidatos.push(new Candidato(nome, 0));

      return console.log(`Candidato ${nome} criado com sucesso!!`);
    });
  }
};

//Função para votar

const votar = (voto_eleitor) => {
  candidatos.forEach((c) => (c.votes = 0));
  for (let index = 0; index < voto_eleitor.length; index++) {
    let participante = candidatos.find((c) => c.name === voto_eleitor[index]); //find é uma função callback que espera uma função, e retorna um objeto se encontrar, senão undefined
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

  candidatos.forEach((candidato) => {
    if (candidato.votes > maior) {
      maior = candidato.votes;
      vencedores = [candidato.name];
    } else if (candidato.votes === maior && maior > 0) {
      vencedores.push(candidato.name);
    }
  });

  if (maior === 0) {
    console.log("Nenhum voto válido foi registrado.");
  } else {
    console.log("Vencedor(es):", vencedores.join(", "));
  }
};
//Entradas para teste
candidatoCreator(["caio2", "Ribamar2", "Pe3dro"]); //Para usar a função forEach, obrigatoriamente o que tem que ser iterado é um Array
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
declararVencedor(candidatos);

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
