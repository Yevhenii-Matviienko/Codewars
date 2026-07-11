using System.Collections.Generic;
using System.Linq;

public static class Kata {
    public static IEnumerable<T> UniqueInOrder<T>(IEnumerable<T> iterable) {
        List<T> result = new List<T>();
        foreach (T item in iterable) {
            if (!result.Any() || !item.Equals(result.Last())) {
                result.Add(item);
            }
        }
        return result;
    }
}