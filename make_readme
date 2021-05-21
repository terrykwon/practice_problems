#!/usr/bin/env python3
import os
from collections import OrderedDict

files_per_dir = OrderedDict((d, 0) for d in [ 
            'code_jam', 
            'codeforces', 
            'cses', 
            'implementations', 
            'leetcode',
          ])

for directory in files_per_dir:
    for dirpath, dirnames, filepaths in os.walk(directory):
        for filepath in filepaths:
            if filepath in ['.DS_Store']:
                continue
            full_path = os.path.join(dirpath, filepath)
            print(full_path)
            files_per_dir[directory] += 1

with open('readme.md', 'w') as f:
    f.write('| Directory | # Problems |\n')
    f.write('| --------- | ---------- |\n')
    for directory, counts in files_per_dir.items():
        f.write('| {} | {} |\n'.format(directory, counts))