export PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"


alias bld="cmake -S ${PROJECT_ROOT} -B build"
