export function getCurrentMicroseconds() {
if (typeof performance != 'undefined') {
    return Math.floor(performance.now() * 1000);
} else {
    return Math.floor(eval('require')('perf_hooks').performance.now() * 1000);
}
}

function leftPad(value: string, minLength: number, padChar = ' ') {
if (value.length < minLength) {
    value = padChar + value;
}
return value;
}

function rightPad(value: string, minLength: number, padChar = ' ') {
if (value.length < minLength) {
    value += padChar;
}
return value;
}

export function formatTime(date: Date) {
    const hours = leftPad(date.getHours().toString(), 2, '0');
    const minutes = leftPad(date.getMinutes().toString(), 2, '0');
    const seconds = leftPad(date.getSeconds().toString(), 2, '0');
    const milliseconds = rightPad(date.getMilliseconds().toString(), 3);
    return `${hours}:${minutes}:${seconds}.${milliseconds}`;
}


export interface Logger {
    debug(componentName: string, message: string): void;
    warn(componentName: string, message: string): void;
    error(componentName: string, message: string): void;
    info(componentName: string, message: string): void;
}

export enum LogLevel {
    Debug,
    Info,
    Warn,
    Error,
}

export class ConsoleLogger implements Logger {
    constructor(
        public currentLogLevel: LogLevel,
        private throwOnError = true,
    ) {}

    private aboveLogLevel(logLevel: LogLevel): boolean {
        return logLevel >= this.currentLogLevel ? true : false;
    }

    private formatMessage(componentName: string, message: string) {
        const currentTime = formatTime(new Date());
        return `${currentTime} [${componentName}] ${message}`;
    }

    debug(componetName: string, message: string): void {
        if (this.aboveLogLevel(LogLevel.Debug)) {
        console.debug(this.formatMessage(componetName, message));
        }
    }

    warn(componetName: string, message: string): void {
        if (this.aboveLogLevel(LogLevel.Warn)) {
        console.warn(this.formatMessage(componetName, message));
        }
    }

    error(componentName: string, message: string): void {
        if (this.aboveLogLevel(LogLevel.Error)) {
        console.error(this.formatMessage(componentName, message));
        if (this.throwOnError) {
            throw new Error(`[${componentName}] ${message}`);
        }
        }
    }

    info(componentName: string, message: string): void {
        if (this.aboveLogLevel(LogLevel.Info)) {
        console.info(this.formatMessage(componentName, message));
        }
    }
}