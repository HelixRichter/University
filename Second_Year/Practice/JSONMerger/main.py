import json

files = ['LOGFILE-1.json', 'LOGFILE-2.json', 'LOGFILE-3.json', 'LOGFILE-4.json']


def merge_jsonfiles(filename):
    result = list()
    for f1 in filename:
        with open(f1, 'r', encoding='utf-8') as infile:
            result.append(json.load(infile))

    with open('LOGFILE.json', 'w', encoding='utf-8') as output_file:
        json.dump(result, output_file)


merge_jsonfiles(files)
