List<int> listNum = [-2, 1, 3, 5, 7, 12];
Dictionary<int, int> possiveisResultados = [];
int result = 1;

for (int i = 0; i< listNum.Count(); i++)
{
    bool resultadoEncontrado = possiveisResultados.TryGetValue(listNum[i], out int valor);
    if (listNum[i] == result)
    {
        Console.WriteLine($"{i}");
        return;
    }
    else if (resultadoEncontrado)
    {
        Console.WriteLine($"{i} {valor}");
        return;
    }

    possiveisResultados.Add(result - listNum[i], i);
}