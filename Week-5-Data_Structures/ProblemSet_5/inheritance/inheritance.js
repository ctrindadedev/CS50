// Each person should have alleles assigned to them. The oldest generation should have alleles randomly chosen (as by calling the random_allele function), and younger generations should inherit one allele (chosen at random) from each parent.
// Each person should have parents assigned to them. The oldest generation should have both parents set to NULL, and younger generations should have parents

// Generation 0, blood type OO
//    Generation 1, blood type AO
//       Generation 2, blood type OA
//       Generation 2, blood type BO
//    Generation 1, blood type OB
//       Generation 2, blood type AO
//       Generation 2, blood type BO

//  Math.random() gera um número entre 0 e 1, sem incluir 1, e, quando multiplicado pelo comprimento do array, é dimensionado para o intervalo do array. Math.floor()Em seguida, é usado para arredondar para baixo, para o número inteiro mais próximo, garantindo que o índice seja válido.

const getRandomItem = (arr) => arr[Math.floor(Math.random() * arr.length)];

const gerarAlelo = () => {
  const alelos = ["A", "B", "O"];
  const aleloEscolhido = getRandomItem(alelos);
  return aleloEscolhido;
};

const escolherAleloAleatorio = (pai) => {
  return getRandomItem(pai.alelos);
};

class Pessoa {
  constructor(generation) {
    if (generation === 0) {
      // Base da árvore: apenas 2 alelos aleatórios, 0 pais
      this.pais = [];
      this.alelos = [gerarAlelo(), gerarAlelo()];
    } else {
      // Cria os pais recursivamente com generation - 1
      const pai1 = new Pessoa(generation - 1);
      const pai2 = new Pessoa(generation - 1);
      this.pais = [pai1, pai2];
      // Cada alelo vem de um dos alelos dos pais
      const alelo1 = escolherAleloAleatorio(pai1);
      const alelo2 = escolherAleloAleatorio(pai2);
      this.alelos = [alelo1, alelo2];
    }
  }
  mostrarArvore(nivel = 0) {
    const space = "  ".repeat(nivel);
    console.log(
      space +
        "Geração " +
        nivel +
        ": Alelos " +
        this.alelos[0] +
        " e " +
        this.alelos[1]
    );
    // Se houver pais, chama recursivamente
    if (this.pais.length > 0) {
      this.pais[0].mostrarArvore(nivel + 1);
      this.pais[1].mostrarArvore(nivel + 1);
    }
  }
}
//Inputs para teste
const pessoa = new Pessoa(2);
pessoa.mostrarArvore();
