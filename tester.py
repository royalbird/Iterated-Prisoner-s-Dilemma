
import os
import subprocess
import sys


points = {'cc': ('K', 2), 'ct': ('R', -1), 'tc': ('S', 4), 'tt': ('E', 1)}


def run(p, h):
    process = subprocess.Popen(['./' + p + '.out' + ' ' + h], shell=True,
                                                    stdout=subprocess.PIPE)
    out = process.communicate()[0]
    out.splitlines()
    return out[0]


def runRounds(p1, p2):
    s1 = 0
    s2 = 0
    h1 = ''
    h2 = ''
    for r in xrange(100):
        r1, r2 = run(p1, h1), run(p2, h2)
        h1 += points[r1 + r2][0]
        h2 += points[r2 + r1][0]
        s1 += points[r1 + r2][1]
        s2 += points[r2 + r1][1]
    return s1, s2


def test_players(players, h):
    for p in players:
        print p + " : " + run(p, h)


def compile_files(players):
    print 'Compiling Files'
    compiled = []
    for p in players:
        ext = os.path.splitext(p)[1]
        if ext == '.cpp':
            cmd, n = 'g++', os.path.basename(p)[:-4]
        if ext == '.c':
            cmd, n = 'gcc', os.path.basename(p)[:-2]
        subprocess.call([cmd, p, '-o', n + '.out'])
        compiled.append(n)
    return compiled


def round_robin(players):
    scores = {}
    for p in players:
        scores[p] = 0
    for p1 in players:
        for p2 in players:
            print 'Running %s against %s' % (p1, p2)
            s1, s2 = runRounds(p1, p2)
            if p1 == p2:
                scores[p1] += (s1 + s2) / 2
            else:
                scores[p1] += s1
                scores[p2] += s2
    return scores


def display_result(scores):
    print "\n\tPOINTS DISTRIBUTION"
    players_sorted = sorted(scores, key=scores.get)
    for p in players_sorted:
        print "\t   %s : %d" % (p, scores[p])
    winner = max(scores, key=scores.get)

    print "\n\tWINNER is %s" % (winner)


def get_players():
    print sys.argv[0] + "\n"
    print 'Finding players in ' + sys.argv[1] + "\n"
    players = [os.curdir + sys.argv[1] + files for files in
                                        os.listdir(os.curdir + sys.argv[1])]
    return players


def main():
    players = get_players()
    players = compile_files(players)
    scores = round_robin(players)
    display_result(scores)

main()

