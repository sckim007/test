pipeline {
    agent any
    triggers {
        pollSCM('* * * * *')
    }
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
    post {
        always {
            mail to: 'sckim007@etri.re.kr',
            subject: "Completed Pipeline: ${currentBuild.fullDisplayName}",
            body: "Your build completed, please check: ${env.BUILD_URL}"
        }
    }
}
