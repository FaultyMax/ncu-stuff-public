
def unikalne(iterable):
    
    uniqs = []

    for item in iterable:
        
        if item in uniqs:
            continue
        else:
            uniqs.append(item)
            yield item


t = unikalne([1, 2, 3, 1, 5, 2, 7, 7, 6])

for i in t:
    print(i)
