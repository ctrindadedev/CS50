def count_letters(text):
    return sum(1 for char in text if char.isalpha())

def count_words(text):

    # Palavras são separadas por espaços
    return len(text.split())

def count_sentences(text):

    # Sentenças terminam em '.', '!' ou '?'
    return sum(1 for char in text if char in ".!?")

def calculate_grade(text):
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # Cálculo das médias por 100 palavras
    L = (letters / words) * 100
    S = (sentences / words) * 100

    # Fórmula de Coleman-Liau utilizada no problema
    index = 0.0588 * L - 0.296 * S - 15.8
    return round(index)

def main():
    text = input("Text: ")
    grade = calculate_grade(text)

    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")

if __name__ == "__main__":
    main()
