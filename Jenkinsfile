pipeline {
    agent any
    stages {
        stage("First Stage") {
            steps {
                echo 'Step 1. Hello World'
            }
        }
        stage("Second Stage") {
            steps {
                echo 'Step 2. Hello World'
            }
        }
        stage("Compile") {
            steps {
                sh "gcc hello.c"
            }
        }
    }
}
