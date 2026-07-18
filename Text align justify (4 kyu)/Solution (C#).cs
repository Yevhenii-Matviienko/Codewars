using System;
using System.Text;
using System.Linq;
using System.Collections.Generic;

namespace Solution {
    public class Kata {
        public static string Justify(string str, int len) {
            string[] words = str.Split(new[] { ' ', '\t', '\n', '\r' }, StringSplitOptions.RemoveEmptyEntries);
            var lines = new List<List<string>>();
            var line = new List<string>();
            foreach (string word in words) {
                int line_words_length = line.Sum(w => w.Length);
                int spaces_between_words = line.Count;
                if (line_words_length + spaces_between_words + word.Length <= len) {
                    line.Add(word);
                }
                else {
                    lines.Add(line);
                    line = new List<string> { word };
                }
            }
            if (line.Count > 0) {
                lines.Add(line);
            }
            var result = new List<string>();
            for (int index_0 = 0; index_0 < lines.Count; index_0++) {
                List<string> current_line = lines[index_0];
                bool check_is_last_line = (index_0 == (lines.Count - 1));
                if (check_is_last_line || current_line.Count == 1) {
                    result.Add(string.Join(" ", current_line));
                    continue;
                }
                int words_length = current_line.Sum(w => w.Length);
                int spaces_length = len - words_length;
                int gaps = current_line.Count - 1;
                int spaces_per_gap = spaces_length / gaps;
                int extra_spaces = spaces_length % gaps;
                var justified_line = new StringBuilder();
                for (int index_1 = 0; index_1 < current_line.Count - 1; index_1++) {
                    justified_line.Append(current_line[index_1]);
                    int spaces = spaces_per_gap;
                    if (index_1 < extra_spaces) {
                        spaces++;
                    }
                    justified_line.Append(' ', spaces);
                }
                justified_line.Append(current_line[current_line.Count - 1]);
                result.Add(justified_line.ToString());
            }
            return string.Join("\n", result);
        }
    }
}