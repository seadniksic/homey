export PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

alias configure="cmake -S ${PROJECT_ROOT} -B build"
alias bld="cmake --build build"
