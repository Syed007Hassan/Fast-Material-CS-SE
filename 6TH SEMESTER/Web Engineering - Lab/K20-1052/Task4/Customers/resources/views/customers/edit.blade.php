@extends('customers.layout')

@section('content')
    <div class="row">
        <div class="col-lg-12 margin-tb">
            <div class="pull-left">
                <h2>Edit Customer</h2>
            </div>
            <div class="pull-right">
                <a class="btn btn-primary" href="{{ route('customers.index') }}"> Back</a>
            </div>
        </div>
    </div>

    @if ($errors->any())
        <div class="alert alert-danger">
            <strong>Whoops!</strong> There were some problems with your input.<br><br>
            <ul>
                @foreach ($errors->all() as $error)
                    <li>{{ $error }}</li>
                @endforeach
            </ul>
        </div>
    @endif

    <form action="{{ route('customers.update', $customer->id) }}" method="POST">
        @csrf
        @method('PUT')

        <div class="row">
            <div class="col-xs-12 col-sm-12 col-md-12">
                <div class="form-group">
                    <strong>Name:</strong>
                    <input type="text" name="name" value="{{ $customer->name }}" class="form-control"
                        placeholder="Name">
                </div>
            </div>
            <div class="col-xs-12 col-sm-12 col-md-12">
                <strong>Email:</strong>
                <input type="email" name="email" value="{{ $customer->email }}" class="form-control"
                    placeholder="Email">
            </div>
            <div class="col-xs-12 col-sm-12 col-md-12">
                <strong>City:</strong>
                <input type="text" name="city" value="{{ $customer->city }}" class="form-control" placeholder="City">
            </div>

            <div class="col-xs-12 col-sm-12 col-md-12">
                <strong>Room Type:</strong>
                <select name="roomType" class="form-control">
                    <option value="">-- Select Room Type --</option>
                    <option name="roomType" value="Single" {{ $customer->roomType == 'Single' ? 'selected' : '' }}>Single
                    </option>
                    <option name="roomType" value="Double" {{ $customer->roomType == 'Double' ? 'selected' : '' }}>Double
                    </option>
                    <option name="roomType" value="Family" {{ $customer->roomType == 'Family' ? 'selected' : '' }}>Family
                    </option>
                </select>
            </div>
            <div class="col-xs-12 col-sm-12 col-md-12 text-center">
                <button type="submit" class="btn btn-primary">Submit</button>
            </div>
        </div>

    </form>
@endsection
