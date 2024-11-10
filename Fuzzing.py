from fuzzingbook.Fuzzer import RandomFuzzer

f = RandomFuzzer()
f.fuzz()

print(f.fuzz())
print(f.fuzz())
print(f.fuzz())

from fuzzingbook.Grammars import simple_grammar_fuzzer

MY_GRAMMAR = {
    "<start>": ["<email>"],
    "<email>": ["<Name>@<domain>.<tld>"],
    "<Name>": ["<string><string><string><string><string>"],
    "<domain>": ["live", "gmail", "hotmail", "concordia"],
    "<tld>": ["com", "org", "net", "io", "ca"],
    "<string>": ["a","b","c","d","e","f","g","h","i","g","k","l","m","n","o","p","q","r","t","u","v","w","y","x","z","1","2","3","0","4","5","6","7","8","9"]
}

print([simple_grammar_fuzzer(MY_GRAMMAR) for i in range(5)])