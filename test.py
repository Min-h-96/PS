words = ['but', 'i', 'wont', 'hesitate', 'no', 'more',
         'no', 'more', 'it', 'cannot', 'wait', 'im', 'yours']
lst = []

for w in words:
    if w not in lst:
        lst.append(w)
print(lst)
