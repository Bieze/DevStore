import argparse


class Parser():
    def __init__(self) -> None:
        self.parser = argparse.ArgumentParser()
        self.parser.add_argument('--integers', metavar='N', type=int, nargs='+',
                                 help='an integer for the accumulator')
        self.parser.parse_args()
