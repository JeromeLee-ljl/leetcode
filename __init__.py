def rename():
    import os

    for file in os.listdir('.'):
        if file[1].isdigit() and file[-2:] != 'py':
            # os.rename()
            print('文件夹', file)
            os.rename(os.path.join(file, '__init__.py'), file + '.py')


if __name__ == '__main__':
    pass
