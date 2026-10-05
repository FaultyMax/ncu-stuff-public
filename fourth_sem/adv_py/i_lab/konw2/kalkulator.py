

def calc(data):

    match data:
        case [a, "+", b]:
            return int(a) + int(b)
        case [a, "-", b]:
            return int(a) - int(b)
        case [a, "*", b]:
            return int(a) * int(b)
        case [a, "/", b]:
            if int(b) != 0:
                return int(a) / int(b)
            else:
                raise ZeroDivisionError("Dzielenie przez zero")
        case _:
            print("Nieznana komenda")


print(calc(input().split()))


'''

tak też

def calc(data):

    match data:

        case [a, op, b]:

            try:
                a = int(a)
                b = int(b)

            except ValueError:
                return "Dozwolone tylko liczby całkowite"

            match op:

                case "+":
                    return a + b

                case "-":
                    return a - b

                case "*":
                    return a * b

                case "/":
                    if b == 0:
                        return "Dzielenie przez zero"

                    return a / b

                case _:
                    return "Nieznany operator"

        case _:
            return "Niepoprawne wyrażenie"


print(calc(input().split()))

'''
