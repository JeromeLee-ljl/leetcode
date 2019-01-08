def rename():
    import os

    for file in os.listdir('.'):
        if file[1].isdigit() and file[-2:] == 'py':
            # os.rename()
            print('_0' + file[1:])
            os.rename(file, '_0' + file[1:])


if __name__ == '__main__':
    a = []
    for i in range(2):
        b = [i]
        a.append(b)
    print(a)

