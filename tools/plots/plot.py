import numpy as np
from matplotlib import pyplot as plot_lib


def run():
    data = read_file("temp_field.csv")
    plot_lib.contourf(
        range(0, data.shape[0]),
        range(0, data.shape[1]),
        data
    )
    plot_lib.savefig("temp_field.png")
    pass


def read_file(filename):
    data = np.loadtxt(filename, delimiter=',')
    return data


if __name__ == "__main__":
    run()
